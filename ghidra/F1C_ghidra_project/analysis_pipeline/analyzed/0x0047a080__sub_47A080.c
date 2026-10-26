// Address: 0x0047a080
// Size: 149 bytes
// Name: sub_47A080
// Type: int __thiscall(_BYTE *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_47A080(_BYTE *this)
{
  int v2; // edi
  float *v3; // ecx
  double v4; // st7
  float v5; // eax
  int v7; // [esp+Ch] [ebp-4h]

  sub_466910();
  v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 8);
  if ( v2 )
  {
    if ( this[256] )
    {
      v7 = *(_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 180))(this);
      if ( (unsigned __int8)sub_490190(v2) )
      {
        v3 = (float *)&unk_7D1448;
        do
        {
          v4 = v3[2];
          v5 = v3[3];
          *(_DWORD *)v3 = v7;
          if ( v4 <= *v3 )
          {
            if ( *v3 > (double)v5 )
              *v3 = v5;
          }
          else
          {
            *v3 = v4;
          }
          v3 += 27;
        }
        while ( (int)v3 < (int)flt_7D17A8 );
      }
    }
  }
  return 0;
}
