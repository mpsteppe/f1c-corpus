// f1c  0x004aa1e0  size=104
char __stdcall sub_4AA1E0(int a1, const char *a2, _BYTE *a3)
{
  char result; // al
  const char *v4; // eax

  result = 0;
  switch ( a1 )
  {
    case 0:
      v4 = aCurnt;
      goto LABEL_9;
    case 1:
      v4 = aPract;
      goto LABEL_9;
    case 2:
      v4 = aQuick;
      goto LABEL_9;
    case 3:
      v4 = aGprix;
      goto LABEL_9;
    case 4:
      v4 = aChamp;
      goto LABEL_9;
    case 5:
      v4 = aMulti;
      goto LABEL_9;
    case 6:
      v4 = aRplay;
LABEL_9:
      sub_58815F(a3, "%s%s", v4, a2);
      result = 1;
      break;
    default:
      *a3 = 0;
      break;
  }
  return result;
}
