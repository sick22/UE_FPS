
# 기능

### Weapon Combat 
	총기와 관련된 input들
### Invertory
	총기 스폰과 장착 관리

### SpawnWeapon()
	무기 생성 및 주체 관리

---

```cpp
if (OwningActor->GetLocalRole() < ROLE_Authority) return nullptr;

```

```
UENUM(BlueprintType)
enum ENetRole : int
{
    ROLE_None,              // 0: 네트워크 복제/동기화에 관여하지 않음
    ROLE_SimulatedProxy,    // 1: 서버로부터 위치/동작을 수신받아 시뮬레이션만 하는 대리자
    ROLE_AutonomousProxy,   // 2: 로컬 플레이어가 직접 조작(입력)하는 대리자
    ROLE_Authority,         // 3: 액터의 최종 권한/소유권을 가진 주체 (일반적으로 서버)
    ROLE_MAX,
};
```

	ROLE_Authority 는 최고 권한
	서버 권한이 없으면 SpawnWeapon 함수를 실행하지 못하도록 보안 작업. 
	중요한 Component/Actor 생성할 때 
---

### ESpawnActorCollisionHandlingMethod

| Enum 값                                                               | 블루프린트                      | 동작                                                             |
| :------------------------------------------------------------------- | :------------------------- | :------------------------------------------------------------- |
| `ESpawnActorCollisionHandlingMethod::Undefined`                      | 기본값 사용 (Use Default)       | 파라미터로 덮어쓰지 않고 액터 클래스 자체 설정(`SpawnCollisionHandlingMethod`)을 따름 |
| `ESpawnActorCollisionHandlingMethod::AlwaysSpawn`                    | 항상 스폰 (Always Spawn)       | 충돌/겹침을 완전히 무시하고 지정된 위치에 무조건 스폰                                 |
| `ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn` | 조정 가능 시 조정하되 항상 스폰         | 충돌하지 않는 가까운 빈 공간으로 위치를 조정하여 스폰, 빈 곳이 없어도 스폰                    |
| `ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawn`   | 조정 가능 시 조정하되 불가능하면 스폰 취소   | 충돌 없는 빈 공간으로 조정을 시도하고, 공간이 없으면 스폰 취소(`nullptr` 반환)             |
| `ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding`           | 충돌 시 스폰 안 함 (Do Not Spawn) | 스폰 위치에 조금이라도 충돌/겹침이 있으면 즉시 스폰 취소(`nullptr` 반환)                 |
