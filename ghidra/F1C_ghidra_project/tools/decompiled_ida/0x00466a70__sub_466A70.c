// Address: 0x00466a70
// Size: 160 bytes
// Name: sub_466A70
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_466A70(_DWORD *this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi

  this[65] = dword_7C7368[this[66]];
  sub_566650(&byte_5EA438);
  if ( !byte_7C7064 )
    sub_430F00(&byte_7C56C0);
  v2 = this[17];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          sub_587BCF(*v5);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  sub_486F30(aCustom_0, -1);
  return 0;
}
