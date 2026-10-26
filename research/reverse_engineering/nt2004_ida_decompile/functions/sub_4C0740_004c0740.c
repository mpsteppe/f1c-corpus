char __thiscall sub_4C0740(char *this, _DWORD *a2)
{
  char v2; // bl
  bool v3; // zf
  int v4; // esi
  char *v5; // eax
  int v6; // ecx
  int v7; // esi
  int v9; // [esp+8h] [ebp-320h] BYREF
  char *v10; // [esp+Ch] [ebp-31Ch]
  char v11[384]; // [esp+10h] [ebp-318h] BYREF
  int v12; // [esp+190h] [ebp-198h]
  char v13; // [esp+194h] [ebp-194h]
  int v14; // [esp+19Ch] [ebp-18Ch]
  int v15; // [esp+1A0h] [ebp-188h]
  int v16; // [esp+1A4h] [ebp-184h]
  char Buffer[384]; // [esp+1A8h] [ebp-180h] BYREF

  v2 = 0;
  v3 = *a2 == 0;
  v10 = this;
  if ( !v3 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v12 = 0;
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 1;
    v9 = 0;
    if ( sub_57A490(Buffer, 384) )
    {
      while ( sub_577B60(v11) )
      {
LABEL_14:
        if ( !sub_57A490(Buffer, 384) )
          return v2;
      }
      v4 = 0;
      while ( 1 )
      {
        v5 = sub_4BFF30((void *)v4);
        if ( sub_578110(v5, (int)&v9, 0, 0, 0) )
          break;
        if ( ++v4 >= 12 )
          goto LABEL_14;
      }
      v6 = v9;
      v7 = v4 << 6;
      if ( v9 >= 0 )
      {
        if ( v9 <= *(_DWORD *)&v10[v7 + 28] - 1 )
        {
LABEL_13:
          *(_DWORD *)&v10[v7 + 32] = v6;
          v2 = 1;
          goto LABEL_14;
        }
        v6 = *(_DWORD *)&v10[v7 + 28] - 1;
      }
      else
      {
        v6 = 0;
      }
      v9 = v6;
      goto LABEL_13;
    }
  }
  return v2;
}
