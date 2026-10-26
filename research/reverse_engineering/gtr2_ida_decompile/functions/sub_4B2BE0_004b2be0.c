int __stdcall sub_4B2BE0(int a1, int a2, int a3, int a4)
{
  int v5; // ebp
  double v6; // st7
  int v7; // edi
  int v8; // esi
  double v9; // st7
  int v10; // esi
  int v11; // eax
  int v12; // ebx
  unsigned __int64 v13; // rax
  int v14; // ebp
  int v15; // edi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  float v19; // [esp+8h] [ebp-68h]
  float v20; // [esp+14h] [ebp-5Ch]
  int v21; // [esp+14h] [ebp-5Ch]
  int v22; // [esp+1Ch] [ebp-54h]
  int v23; // [esp+20h] [ebp-50h]
  char *i; // [esp+24h] [ebp-4Ch]
  double v25[8]; // [esp+28h] [ebp-48h]
  int v26; // [esp+6Ch] [ebp-4h]
  char *retaddr; // [esp+70h] [ebp+0h] BYREF
  int v28; // [esp+74h] [ebp+4h]
  int v29; // [esp+74h] [ebp+4h]

  sub_4D6060(a1, a2, a3, a4);
  if ( !(unsigned __int8)sub_4CFDA0(0, &a4) || !(unsigned __int8)sub_4CFDA0(1, &retaddr) )
    return 0;
  if ( dword_FB1CE0 && dword_FB2790 )
  {
    v28 = a2 * *((_DWORD *)dword_FB2790 + 1);
    v19 = (double)v28 * 0.00125;
    sub_4015C0(v19);
    return off_16C9288(v28, a2, a3, a4);
  }
  else
  {
    v5 = sub_435580();
    v22 = v5;
    v29 = (unsigned __int64)(((double)dword_B65714 * dbl_B65708 + dbl_B65700)
                           * 9.549296585513721
                           * 0.0001
                           * (double)((char *)&a2 - retaddr)
                           + (double)(int)retaddr);
    if ( byte_B72478 )
      v6 = 3.6;
    else
      v6 = 2.236936292054402;
    v20 = v6;
    v7 = a2;
    v8 = 0;
    v23 = a2;
    for ( i = retaddr; v8 < v5; *((double *)&v23 + v8) = v9 * v20 )
      v9 = sub_4355B0((int)&byte_B64150, v8++);
    v10 = (unsigned __int64)((double)(v26 - a2) * (v25[0] * 0.01) + (double)a2);
    v11 = sub_4DDFE0(&unk_B6E2A0, (unsigned __int64)((double)(v26 - a2) * (v25[0] * 0.01) + (double)a2) >> 32);
    if ( v11 )
      sub_4DDDB0(v7, retaddr, v10, v29, byte_FFFFFF, v11);
    v21 = 1;
    if ( v5 > 1 )
    {
      while ( 1 )
      {
        v12 = v10;
        v13 = (unsigned __int64)(v25[v21] * 0.01 * (double)(v26 - a2) + (double)a2);
        v10 = v13;
        if ( v7 == (_DWORD)v13 )
        {
          v14 = 10;
          v15 = 10;
        }
        else
        {
          v14 = v12;
          v13 = (unsigned __int64)((double)(v29 - (int)i) / (double)((int)v13 - v7) * (double)((int)v13 - v12));
          v15 = v29 - v13;
        }
        v16 = sub_4DDFE0(&unk_B6E2A0, HIDWORD(v13));
        if ( v16 )
          sub_4DDDB0(v12, v29, v14, v15, byte_FFFFFF, v16);
        v18 = sub_4DDFE0(&unk_B6E2A0, v17);
        if ( v18 )
          sub_4DDDB0(v14, v15, v10, v29, byte_FFFFFF, v18);
        if ( ++v21 >= v22 )
          break;
        v7 = v23;
      }
    }
    return 0;
  }
}
