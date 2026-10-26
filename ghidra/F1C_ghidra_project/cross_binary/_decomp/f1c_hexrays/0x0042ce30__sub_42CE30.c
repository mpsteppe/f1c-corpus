// f1c  0x0042ce30  size=112
char *__fastcall sub_42CE30(int a1, char a2)
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
        goto LABEL_14;
      case 6:
        goto LABEL_15;
      case 7:
        goto LABEL_16;
      default:
        goto LABEL_17;
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
LABEL_14:
        result = aQualify;
        break;
      case 6:
LABEL_15:
        result = aWarmup;
        break;
      case 7:
LABEL_16:
        result = aRace_0;
        break;
      default:
LABEL_17:
        result = aUnknown;
        break;
    }
  }
  return result;
}
