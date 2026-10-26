// f1c  0x004d9030  size=139
int __stdcall sub_4D9030(int a1)
{
  int result; // eax
  int *v2; // esi
  void *v3; // esi

  result = a1 - 1;
  switch ( a1 )
  {
    case 1:
      v2 = &dword_8AD398;
      goto LABEL_7;
    case 2:
      v2 = &dword_8AD39C;
      goto LABEL_7;
    case 3:
      v2 = &dword_8AD3A0;
      goto LABEL_7;
    case 4:
      v2 = &dword_8AD3A4;
      goto LABEL_7;
    case 5:
      v2 = (int *)&flt_8AD3A8;
LABEL_7:
      result = *v2;
      if ( *v2 )
      {
        result = sub_5539F0(*v2);
        *v2 = 0;
      }
      break;
    default:
      break;
  }
  if ( a1 == 3 && dword_8AD3AC )
  {
    result = sub_5502C0(dword_8AD3AC);
    v3 = (void *)dword_8AD3AC;
    if ( dword_8AD3AC )
    {
      j_nullsub_3(dword_8AD3AC);
      result = sub_587BCF(v3);
    }
    dword_8AD3AC = 0;
  }
  return result;
}
