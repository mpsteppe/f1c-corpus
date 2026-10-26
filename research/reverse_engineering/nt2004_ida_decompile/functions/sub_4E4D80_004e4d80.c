int __thiscall sub_4E4D80(char *this, char *String2)
{
  int v3; // edi
  int v4; // ebx
  char *v5; // eax
  int v6; // esi
  char *v7; // eax
  int v9; // [esp+10h] [ebp-BCh]
  int v10; // [esp+14h] [ebp-B8h]
  int i; // [esp+18h] [ebp-B4h]
  char v12[48]; // [esp+1Ch] [ebp-B0h] BYREF
  char String1[64]; // [esp+4Ch] [ebp-80h] BYREF
  char v14[64]; // [esp+8Ch] [ebp-40h] BYREF

  memset(v12, 0, sizeof(v12));
  if ( !String2 )
    return -1;
  v10 = sub_4E4CD0(this, (int)String2);
  v9 = 1;
  v3 = sub_4E4C30(this) + 1;
  v4 = 0;
  if ( v3 <= 0 )
    return 1;
  do
  {
    if ( !v12[v4] )
    {
      v5 = v4 ? (char *)sub_4E4C60(this, v4 - 1) : sub_4E4C50(this);
      if ( v5 )
      {
        v12[v4] = 1;
        sub_4E3D70(v5, String1);
        if ( _strcmpi(String1, String2) )
        {
          v6 = v4 + 1;
          for ( i = sub_4E4CD0(this, (int)String1); v6 < v3; ++v6 )
          {
            if ( v6 )
              v7 = (char *)sub_4E4C60(this, v6 - 1);
            else
              v7 = sub_4E4C50(this);
            sub_4E3D70(v7, v14);
            if ( !_strcmpi(v14, String1) )
              v12[v6] = 1;
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
