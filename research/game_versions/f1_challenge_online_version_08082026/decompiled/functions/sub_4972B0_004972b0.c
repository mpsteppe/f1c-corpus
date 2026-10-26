int __stdcall sub_4972B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // ebx
  int v8; // ebp
  int v9; // esi
  int v10; // edi
  int v11; // eax
  int result; // eax
  unsigned int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  unsigned int v18; // [esp+14h] [ebp+4h]
  int v19; // [esp+20h] [ebp+10h]
  int v20; // [esp+24h] [ebp+14h]

  v7 = a5;
  v8 = a7;
  v9 = a4;
  v10 = a6;
  v11 = sub_495150();
  sub_494BF0(v11, a6, a4, a7 - a6, a5 - a4, a1);
  result = a3;
  v20 = 0;
  if ( a3 > 0 )
  {
    v13 = a1 & 0xFF000000 | ~a2 & 0xFFFFFF;
    v18 = a1 & 0xFF000000 | a2 & 0xFFFFFF;
    v19 = v13;
    do
    {
      if ( v20 > 0 )
      {
        ++v9;
        --v7;
        ++v10;
        --v8;
      }
      v14 = sub_495150();
      sub_494C20(v10, v9, v8, v9, v18, v14);
      v15 = sub_495150();
      sub_494C20(v8, v9, v8, v7, v18, v15);
      v16 = sub_495150();
      sub_494C20(v10, v7, v8, v7, v19, v16);
      v17 = sub_495150();
      sub_494C20(v10, v9, v10, v7, v19, v17);
      result = ++v20;
    }
    while ( v20 < a3 );
  }
  return result;
}
