int __thiscall sub_4980D0(const char *this, char *a2, int a3, int a4, int a5, int a6, char a7)
{
  const char *v7; // ebx
  int v9; // esi
  char *v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // eax
  int **v14; // eax
  int v15; // [esp-14h] [ebp-20h]
  char v16; // [esp-10h] [ebp-1Ch]
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp+4h] [ebp-8h] BYREF
  const char *v19; // [esp+8h] [ebp-4h]

  v7 = a2;
  if ( !a2 )
    return -1;
  v9 = (int)(this + 5400);
  v19 = this + 5400;
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
    sub_494F00(v9, (int)v10, (int)&v18, (int)&a2);
    v11 = a5 + (a6 - a5) / 2;
    if ( a4 - a3 <= (int)a2 )
      v12 = a3;
    else
      v12 = a3 + (a4 - a3) / 2 - (int)a2 / 2;
    v16 = a7;
    v13 = sub_495150();
    sub_494F10((int)v19, v7, v11 - v18 / 2, v12, v13, v16);
    v17 = (int)(a2 + 30);
    v15 = v18 + 20;
    v14 = (int **)sub_490920();
    sub_4918D0(v14, v11, v12, v15, v17);
  }
  return 0;
}
