int __cdecl sub_637022(int a1, int *a2)
{
  int *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // eax
  int v8; // eax
  int v9; // edi
  int v10; // edi
  _BYTE *v11; // eax

  v2 = a2;
  v3 = a2[3];
  v4 = a2[4];
  if ( (v3 & 0x82) == 0 || (v3 & 0x40) != 0 )
    goto LABEL_21;
  if ( (v3 & 1) != 0 )
  {
    a2[1] = 0;
    if ( (v3 & 0x10) != 0 )
    {
      *v2 = v2[2];
      v2[3] = v3 & 0xFFFFFFFE;
      goto LABEL_6;
    }
LABEL_21:
    v2[3] = v3 | 0x20;
    return -1;
  }
LABEL_6:
  v5 = v2[3];
  v2[1] = 0;
  a2 = 0;
  v6 = v5 & 0xFFFFFFED | 2;
  v2[3] = v6;
  if ( (v6 & 0x10C) == 0 )
    return off_16C94A0(a1, a2);
  if ( (v2[3] & 0x108) != 0 )
  {
    v8 = v2[2];
    v9 = *v2;
    *v2 = v8 + 1;
    v10 = v9 - v8;
    v2[1] = v2[6] - 1;
    if ( v10 <= 0 )
    {
      if ( v4 == -1 )
        v11 = &unk_913430;
      else
        v11 = (_BYTE *)(dword_FBB4E0[v4 >> 5] + 36 * (v4 & 0x1F));
      if ( (v11[4] & 0x20) != 0 )
        _lseek(v4, 0, 2);
    }
    else
    {
      a2 = (int *)sub_638801(v4, v8, v10);
    }
    *(_BYTE *)v2[2] = a1;
  }
  else
  {
    v10 = 1;
    a2 = (int *)sub_638801(v4, &a1, 1);
  }
  if ( a2 == (int *)v10 )
    return (unsigned __int8)a1;
  v2[3] |= 0x20u;
  return -1;
}
