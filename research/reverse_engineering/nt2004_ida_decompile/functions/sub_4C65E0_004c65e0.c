char __stdcall sub_4C65E0(int a1, const char *a2, char *Buffer)
{
  char result; // al
  const char *v4; // eax

  result = 0;
  switch ( a1 )
  {
    case 0:
      v4 = aCurnt;
      goto LABEL_11;
    case 1:
      v4 = aPract;
      goto LABEL_11;
    case 2:
      v4 = aQuick;
      goto LABEL_11;
    case 3:
      v4 = aGprix;
      goto LABEL_11;
    case 4:
      v4 = aChamp;
      goto LABEL_11;
    case 5:
      v4 = aMulti;
      goto LABEL_11;
    case 6:
      v4 = aDrsch;
      goto LABEL_11;
    case 7:
      v4 = aRplay;
      goto LABEL_11;
    case 8:
      v4 = aCareer_2;
LABEL_11:
      sprintf(Buffer, "%s%s", v4, a2);
      result = 1;
      break;
    default:
      *Buffer = 0;
      break;
  }
  return result;
}
