int __thiscall sub_5B29A0(_DWORD *this, char *a2, _DWORD *a3)
{
  void *v4; // eax
  char *v5; // ebx
  int v7; // [esp+8h] [ebp-114h]
  char String[16]; // [esp+Ch] [ebp-110h] BYREF
  char v9[256]; // [esp+1Ch] [ebp-100h] BYREF

  v7 = 0;
  v4 = operator new(0x108u);
  if ( v4 )
    v5 = (char *)sub_594090((int)v4);
  else
    v5 = 0;
  *(_DWORD *)v5 = this;
  while ( sub_5B1A10(a3) != 1 )
  {
    if ( *a3 == 3 )
      break;
    if ( *a3 != 2 )
    {
      sub_5B1DC0((int)a3, aType, String, 0);
      if ( sub_5B1DC0((int)a3, aInstance, v9, 0) )
        sub_594290(v5, v9);
      if ( sub_5B1DC0((int)a3, aLight, v9, 0) )
        sub_594440(v5, (int)v9);
      if ( sub_5B1DC0((int)a3, aLink, v9, 0) )
        sub_594570(v5, v9);
      if ( sub_5B1DC0((int)a3, aAdjacent, v9, 0) )
        sub_594630(v5, v9);
    }
  }
  if ( !strcmp(String, aStorage) )
    v7 = 64;
  if ( !strcmp(String, aInstance) )
    v7 = 128;
  sub_5940F0(v5, a2, v7);
  sub_5954E0(this, (int)v5);
  return 0;
}
