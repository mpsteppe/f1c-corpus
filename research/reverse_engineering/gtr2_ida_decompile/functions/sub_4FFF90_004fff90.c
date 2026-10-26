char __userpurge sub_4FFF90@<al>(float *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, float a5)
{
  double v6; // st7
  float *v7; // ecx
  float v8; // eax
  int v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // ecx
  float v14; // [esp+4h] [ebp-24h]
  float v15; // [esp+4h] [ebp-24h]
  float v16[3]; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD v17[4]; // [esp+18h] [ebp-10h] BYREF
  int retaddr; // [esp+28h] [ebp+0h]

  v6 = a5 - a1[195];
  if ( v6 > 10.0 && v6 < 11.0 || v6 > 17.0 && v6 < 18.0 )
    sub_4EE320(53, *(_DWORD *)a1);
  v7 = *(float **)a1;
  *((_BYTE *)a1 + 765) = 1;
  v14 = v7[4003];
  v8 = v7[4004];
  v16[0] = v7[4005];
  if ( v16[0] * v16[0] + v8 * v8 + v14 * v14 > 0.040000003 )
    *((_BYTE *)a1 + 765) = 0;
  sub_578670(v7 + 4, 1, a3, a4, a2);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 14820) == 1 )
  {
    sub_573480(0);
    *((_BYTE *)a1 + 765) = sub_4278D0(*(_DWORD **)a1);
  }
  else if ( dword_B6E4D0 == 1 )
  {
    *((_BYTE *)a1 + 765) = 0;
    sub_4FFF30(a1, retaddr, 0);
  }
  LOBYTE(v9) = *((_BYTE *)a1 + 765);
  if ( (_BYTE)v9 )
  {
    v10 = (_DWORD *)*((_DWORD *)a1 + 2);
    if ( v10 )
    {
      v15 = *(float *)(*(_DWORD *)a1 + 15992);
      sub_4F0CB0(v10, v16, v17);
      v16[1] = v15;
      sub_57DE20(v16, v17);
    }
    sub_4FFF30(a1, retaddr, 1);
    v9 = (_BYTE)dword_757C1C != 0 ? dword_91E084 : 0;
    if ( *(_DWORD *)a1 == v9 )
    {
      LOBYTE(v9) = *((_BYTE *)a1 + 808);
      if ( !(_BYTE)v9 )
      {
        v9 = *((_DWORD *)a1 + 27);
        if ( !v9 )
        {
          LOBYTE(v9) = dword_B71278;
          if ( dword_B71278 > 0 )
            LOBYTE(v9) = sub_4FCB90();
        }
      }
    }
    v11 = (_DWORD *)*((_DWORD *)a1 + 2);
    if ( v11 )
    {
      if ( (v11[3] & 1) != 0 )
      {
        sub_4F0D10();
        LOBYTE(v9) = sub_4F1BF0(*((void **)a1 + 2), 1);
        if ( (_BYTE)v9 )
          LOBYTE(v9) = sub_4F14A0();
      }
    }
  }
  return v9;
}
