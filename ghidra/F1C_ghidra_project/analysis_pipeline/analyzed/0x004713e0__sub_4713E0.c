// Address: 0x004713e0
// Size: 92 bytes
// Name: sub_4713E0
// Type: int __thiscall(_DWORD *this, int)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4713E0(_DWORD *this, int a2)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax
  _BYTE v6[32]; // [esp+0h] [ebp-20h] BYREF

  v2 = (int *)this[200];
  v3 = *v2;
  if ( a2 == 1 )
    v4 = v3 + 1;
  else
    v4 = v3 - 1;
  if ( v4 >= 0 )
  {
    if ( v4 > 1 )
      v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
    *v2 = 1;
  else
    *v2 = 0;
  return sub_48B810(v6);
}
