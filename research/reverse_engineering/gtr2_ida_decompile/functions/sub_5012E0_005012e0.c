char __stdcall sub_5012E0(int a1, const char *a2, char *Buffer)
{
  char result; // al
  const char *v4; // eax

  result = 0;
  switch ( a1 )
  {
    case 0:
      v4 = "CURNT ";
      goto LABEL_11;
    case 1:
      v4 = "PRACT ";
      goto LABEL_11;
    case 2:
      v4 = "QUICK ";
      goto LABEL_11;
    case 3:
      v4 = "FRACE ";
      goto LABEL_11;
    case 4:
      v4 = "CHAMP ";
      goto LABEL_11;
    case 5:
      v4 = "MULTI ";
      goto LABEL_11;
    case 6:
      v4 = "RPLAY ";
      goto LABEL_11;
    case 7:
      v4 = "TIMET ";
      goto LABEL_11;
    case 8:
      v4 = "DSCHL ";
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
