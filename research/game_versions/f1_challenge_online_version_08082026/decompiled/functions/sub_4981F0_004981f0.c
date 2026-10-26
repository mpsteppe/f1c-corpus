int __thiscall sub_4981F0(const char *this, char *a2, int a3, int a4, int a5, int a6, char a7)
{
  const char *v7; // ebp
  int v9; // ebx
  char *v10; // eax
  int v11; // esi
  int v12; // eax
  char v13; // [esp-10h] [ebp-18h]
  _BYTE v14[4]; // [esp+4h] [ebp-4h] BYREF

  v7 = a2;
  if ( !a2 )
    return -1;
  v9 = (int)(this + 5400);
  if ( strlen(this + 5400) )
  {
    if ( a7 )
    {
      if ( sub_423A00(byte_5EC4C0, a2, byte_5EC4CC) )
        strcpy(byte_5EC4CC, v7);
      v10 = byte_5EC4CC;
    }
    else
    {
      v10 = a2;
    }
    sub_494F00(v9, (int)v10, (int)v14, (int)&a2);
    if ( a4 - a3 <= (int)a2 )
      v11 = a3;
    else
      v11 = a3 + (a4 - a3) / 2 - (int)a2 / 2;
    v13 = a7;
    v12 = sub_495150();
    sub_494F10(v9, v7, a5, v11, v12, v13);
  }
  return 0;
}
