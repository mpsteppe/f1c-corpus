int __thiscall sub_4B6470(_DWORD *this, char *FileName)
{
  FILE *v3; // edi
  int result; // eax
  int *v5; // esi
  int v6; // [esp+Ch] [ebp-424h] BYREF
  int v7; // [esp+10h] [ebp-420h] BYREF
  int v8[130]; // [esp+14h] [ebp-41Ch] BYREF
  char v9; // [esp+21Ch] [ebp-214h]
  int v10; // [esp+224h] [ebp-20Ch]
  int v11; // [esp+228h] [ebp-208h]
  int v12; // [esp+22Ch] [ebp-204h]
  char Buffer[512]; // [esp+230h] [ebp-200h] BYREF

  memset(Buffer, 0, sizeof(Buffer));
  v8[129] = 0;
  v12 = 0;
  v10 = 0;
  v11 = 0;
  v9 = 1;
  v6 = 0;
  v3 = fopen(FileName, "rt");
  result = sub_525140(this + 94);
  this[90] = 0;
  if ( v3 )
  {
    while ( (v3->_flag & 0x10) == 0 )
    {
      v5 = (int *)operator new(0xCu);
      fgets(Buffer, 512, v3);
      sub_6133A0("NumCoordinates", (int)&v6, 0, 0, 0);
      if ( v6 > 0 )
      {
        if ( sub_6133A0("Coordinate", (int)&v7, (int)v8, 0, 0) )
        {
          *v5 = v7;
          v5[1] = v8[0];
          sub_5FDFB0(v5, 1);
          ++this[90];
        }
      }
    }
    return fclose(v3);
  }
  return result;
}
