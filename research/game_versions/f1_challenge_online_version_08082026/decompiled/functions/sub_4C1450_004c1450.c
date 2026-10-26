int __thiscall sub_4C1450(char *this, int a2)
{
  int v3; // edi
  int v4; // ebx
  char *v5; // eax
  int v6; // esi
  char *v7; // eax
  int v9; // [esp+10h] [ebp-B4h]
  int v10; // [esp+14h] [ebp-B0h]
  int i; // [esp+18h] [ebp-ACh]
  _BYTE v12[32]; // [esp+1Ch] [ebp-A8h] BYREF
  _BYTE v13[32]; // [esp+3Ch] [ebp-88h] BYREF
  _BYTE v14[104]; // [esp+5Ch] [ebp-68h] BYREF

  memset(v14, 0, sizeof(v14));
  if ( !a2 )
    return -1;
  v10 = sub_4C13C0(this, a2);
  v9 = 1;
  v3 = sub_4C1370(this) + 1;
  v4 = 0;
  if ( v3 <= 0 )
    return 1;
  do
  {
    if ( !v14[v4] )
    {
      v5 = v4 ? sub_4C13A0(this, v4 - 1) : sub_4C1390(this);
      if ( v5 )
      {
        v14[v4] = 1;
        sub_4C0A20(v5, v12, 0x20u);
        if ( sub_588410(v12, a2) )
        {
          v6 = v4 + 1;
          for ( i = sub_4C13C0(this, (int)v12); v6 < v3; ++v6 )
          {
            if ( v6 )
              v7 = sub_4C13A0(this, v6 - 1);
            else
              v7 = sub_4C1390(this);
            sub_4C0A20(v7, v13, 0x20u);
            if ( !sub_588410(v13, v12) )
              v14[v6] = 1;
          }
          if ( i > v10 )
            ++v9;
        }
      }
    }
    ++v4;
  }
  while ( v4 < v3 );
  return v9;
}
