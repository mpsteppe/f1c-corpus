// f1c  0x0058bf45  size=167
_BYTE *__cdecl sub_58BF45(_BYTE *a1, signed int a2, _DWORD *a3, char a4)
{
  int v4; // eax
  _BYTE *v5; // eax
  _BYTE *v6; // edi
  int v7; // eax
  _BYTE *v8; // edi
  int v9; // esi
  unsigned __int8 *v10; // edi
  int v11; // esi

  v4 = a3[1] - 1;
  if ( a4 && v4 == a2 )
  {
    v5 = &a1[v4 + (*a3 == 45)];
    *v5 = 48;
    v5[1] = 0;
  }
  v6 = a1;
  if ( *a3 == 45 )
  {
    *a1 = 45;
    v6 = a1 + 1;
  }
  v7 = a3[1];
  if ( v7 > 0 )
  {
    v8 = &v6[v7];
  }
  else
  {
    sub_58C0D0(v6, 1);
    *v6 = 48;
    v8 = v6 + 1;
  }
  if ( a2 > 0 )
  {
    sub_58C0D0(v8, 1);
    *v8 = byte_5E6BD8;
    v9 = a3[1];
    v10 = v8 + 1;
    if ( v9 < 0 )
    {
      if ( a4 )
      {
        v11 = -v9;
      }
      else
      {
        v11 = -v9;
        if ( a2 < v11 )
        {
LABEL_15:
          sub_58C0D0(v10, a2);
          sub_58BB10(v10, 0x30u, a2);
          return a1;
        }
      }
      a2 = v11;
      goto LABEL_15;
    }
  }
  return a1;
}
