// f1c  0x004d8130  size=230
int __stdcall sub_4D8130(float a1, char a2)
{
  char v2; // dl
  int v3; // eax
  char v4; // cl
  int v5; // ebx
  int v6; // ebp
  int v7; // eax
  char v9[8]; // [esp+4h] [ebp-28h] BYREF
  char v10[32]; // [esp+Ch] [ebp-20h] BYREF

  v2 = byte_5D4A60;
  if ( !a2 )
    v2 = byte_5D4A61;
  v3 = 0;
  do
  {
    v4 = byte_5EA438[v3];
    v10[v3++] = v4;
  }
  while ( v4 );
  v5 = 0;
  if ( dword_5D4A64 > 0 )
  {
    v6 = v2;
    do
    {
      sub_58815F(v9, "%c", v5 + v6);
      v7 = dword_5D4A64;
      strcat(v10, v9);
      ++v5;
    }
    while ( v5 < v7 );
  }
  if ( a1 <= 0.0 )
    a1 = 0.001;
  return sub_4D7E40((int)v10, 640, 974, 0xFFFFFF, 2, 3, 1.0, a1);
}
