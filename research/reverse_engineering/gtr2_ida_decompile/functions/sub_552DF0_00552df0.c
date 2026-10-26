void __thiscall sub_552DF0(_DWORD *this)
{
  char *v2; // ebp
  char *v3; // ebx
  float *v4; // eax
  int v5; // esi
  int i; // edi
  int v7; // eax
  int v8; // eax
  bool v9; // [esp+1h] [ebp-49h]
  float v10[6]; // [esp+2h] [ebp-48h] BYREF
  char v11; // [esp+32h] [ebp-18h] BYREF

  v2 = (char *)(this + 1);
  sub_54EE50(this + 1);
  v3 = (char *)(this + 210);
  sub_54EE50(this + 210);
  this[419] = 0;
  this[446] = 0;
  memset(this + 420, 0xFFu, 0x68u);
  LODWORD(v10[0]) = &v11;
  *(_BYTE *)this = 1;
  sub_4035C0();
  sub_4035C0();
  v9 = 1;
  v4 = sub_402D40(&flt_91BCA0, v10, 0);
  if ( v4 && !*((_DWORD *)v4 + 76) )
    v9 = v10[4] * v4[10] + v10[5] * v4[11] + v10[3] * v4[9] >= v10[2] * v4[11] + v10[1] * v4[10] + v10[0] * v4[9];
  v5 = dword_757C10;
  for ( i = 1; i <= v5; ++i )
  {
    v7 = 0;
    if ( v5 > 0 )
    {
      while ( i != *(_DWORD *)(*(&dword_91E088 + v7) + 19324) )
      {
        if ( ++v7 >= v5 )
          goto LABEL_14;
      }
      v8 = *(&dword_91E088 + v7);
      if ( v9 != (i % 2 == 0) )
      {
        if ( v8 )
        {
          *(_DWORD *)&v2[8 * *((_DWORD *)v2 + 208)] = *(_DWORD *)(v8 + 22468);
          *(_DWORD *)&v2[8 * (*((_DWORD *)v2 + 208))++ + 4] = 0;
        }
      }
      else if ( v8 )
      {
        *(_DWORD *)&v3[8 * *((_DWORD *)v3 + 208)] = *(_DWORD *)(v8 + 22468);
        *(_DWORD *)&v3[8 * (*((_DWORD *)v3 + 208))++ + 4] = 0;
      }
    }
LABEL_14:
    ;
  }
}
