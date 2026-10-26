void __thiscall sub_45D100(void *this, int a2, int a3, int a4, char a5)
{
  int v5; // ebp
  int v6; // ebx
  int v7; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  char *v11; // ebx
  char Destination[128]; // [esp+Ch] [ebp-80h] BYREF

  if ( a3 <= dword_76887C )
  {
    if ( a4 == 16909060 )
      a4 = sub_45CE90(a3);
    v5 = 128;
    if ( dword_6152E8 / 13 <= 128 )
      v5 = dword_6152E8 / 13;
    v6 = 0;
    while ( (int)strlen((const char *)(v6 + a2)) >= v5 )
    {
      strncpy(Destination, (const char *)(v6 + a2), v5 - 1);
      v7 = v5 >> 1;
      v8 = v5 - 2;
      v9 = v5 - 2 == v5 >> 1;
      Destination[v5 - 1] = 0;
      if ( v5 - 2 > v5 >> 1 )
      {
        do
        {
          if ( Destination[v8] == 32 )
            break;
          --v8;
        }
        while ( v8 > v7 );
        v9 = v8 == v7;
      }
      if ( v9 )
        v10 = v5 - 1;
      else
        v10 = v8 + 1;
      v6 += v10;
      Destination[v10] = 0;
      if ( a5 )
        sub_45CD60((_DWORD *)(*(_DWORD *)this + 8), Destination, 0);
      else
        sub_45CCB0((char *)(*(_DWORD *)this + 8), Destination, a4, 1084227584, a3);
    }
    v11 = (char *)(a2 + v6);
    if ( a5 )
      sub_45CD60((_DWORD *)(*(_DWORD *)this + 8), v11, 0);
    else
      sub_45CCB0((char *)(*(_DWORD *)this + 8), v11, a4, 1084227584, a3);
  }
}
