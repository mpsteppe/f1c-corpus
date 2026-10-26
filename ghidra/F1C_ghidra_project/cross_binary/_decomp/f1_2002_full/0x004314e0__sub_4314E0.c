// f1_2002_full  0x004314e0  size=124
char *__fastcall sub_4314E0(int a1, char a2)
{
  char *result; // eax

  if ( a2 )
  {
    switch ( a1 )
    {
      case 0:
        result = aTestDay;
        break;
      case 1:
        result = aPractice1;
        break;
      case 2:
        result = aPractice2;
        break;
      case 3:
        result = aPractice3;
        break;
      case 4:
        result = aPractice4;
        break;
      case 5:
        goto LABEL_8;
      case 6:
        goto LABEL_9;
      case 7:
        goto LABEL_10;
      case 8:
        result = aDrivingSchool;
        break;
      default:
        goto LABEL_19;
    }
  }
  else
  {
    switch ( a1 )
    {
      case 0:
        result = aTestday;
        break;
      case 1:
        result = aPractice1_0;
        break;
      case 2:
        result = aPractice2_0;
        break;
      case 3:
        result = aPractice3_0;
        break;
      case 4:
        result = aPractice4_0;
        break;
      case 5:
LABEL_8:
        result = aQualify;
        break;
      case 6:
LABEL_9:
        result = aWarmup;
        break;
      case 7:
LABEL_10:
        result = aRace_0;
        break;
      case 8:
        result = aDrivingschool;
        break;
      default:
LABEL_19:
        result = aUnknown;
        break;
    }
  }
  return result;
}
