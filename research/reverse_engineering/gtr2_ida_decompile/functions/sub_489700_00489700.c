char __usercall sub_489700@<al>(float *a1@<ecx>, int a2@<esi>)
{
  char v3; // bl
  double v4; // st7
  double v5; // st7
  float v7; // [esp+8h] [ebp-64h]
  float v8; // [esp+Ch] [ebp-60h]
  _BYTE v9[80]; // [esp+10h] [ebp-5Ch] BYREF
  int v10; // [esp+68h] [ebp-4h]

  v3 = 0;
  if ( sub_489660((DWORD *)a1) )
  {
    v3 = 1;
    sub_617DB0(v9, a2);
    v10 = 0;
    sub_617DF0(1);
    sub_617E70(v9);
    v8 = 1.0 / (double)dword_B735E8;
    sub_45DDE0();
    v7 = 0.0;
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = sub_617F80(v9) + v7;
        if ( v4 >= v8 )
          break;
        Sleep(0);
      }
      v5 = v4 - v8;
      v7 = v5 <= 0.5 ? v5 : 0.5;
      sub_617E70(v9);
      sub_484200(a1);
      if ( !sub_488A20(a1) )
        break;
      if ( !dword_757C10 )
        Sleep(5u);
    }
    sub_481D60((const CHAR ****)a1);
    v10 = -1;
    nullsub_7(v9);
  }
  return v3;
}
