## 프로젝트 설명
- 실제 작동은 하지 않는, 임의로 작성한 샘플 코드입니다. 구조와 플로우 위주로 작성했고, 변수와 함수 정의 등이 비어있을 수 있습니다.
- 위젯 블루프린트는 없습니다. C++ 코드만 작성하였습니다.

## 툴팁 시스템
- /DataTypes/YSTooltipDataTypes : 툴팁에 필요한 데이터 모음. 툴팁용 구조체를 만듦.
- /UI/YSTooltipUIContainer : 툴팁을 생성하는 곳.
- /UI/YSTooltipUIBase : 툴팁 UI 기반 클래스. 이를 상속받아 필요한 타입의 툴팁을 만든다.
- /UI/YSTooltipUIWithKeyGuide : 키 가이드가 필요한 툴팁 UI의 기반 클래스. 키 가이드가 필요한 툴팁들은 이 클래스를 상속받아 만든다.
- /UI/YSTooltipUIInputProcessor : 툴팁 키 가이드에 따른 입력을 받아 정해진 작업을 수행하도록 함.
- /Table/YSTooltipTable : 언리얼 데이터 테이블에 툴팁 타입과 위젯을 등록할 수 있는 테이블 클래스.
   
## 아이템 구조
- /DataTypes/YSItemDataTypes : 다양한 아이템 데이터를 구조화함.
- /Util/YSItemUtility : 아이템 관련 유용한 함수, 공용 함수 등을 정의.
   
## 티켓 구조
- /Book/YSTicketBook : 티켓 타입, 컨텐츠, 티켓 사용 방식 등에 따른 티켓 데이터 구조 정의.
