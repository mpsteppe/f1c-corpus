int __thiscall sub_696AE1(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  unsigned int v3; // edi
  int result; // eax
  int v6; // ebx
  int v7[9]; // [esp+8h] [ebp-5Ch] BYREF
  int v8[9]; // [esp+2Ch] [ebp-38h] BYREF
  int v9; // [esp+50h] [ebp-14h]
  int v10; // [esp+54h] [ebp-10h] BYREF
  unsigned int v11; // [esp+58h] [ebp-Ch]
  unsigned int v12; // [esp+5Ch] [ebp-8h]
  int v13; // [esp+60h] [ebp-4h]

  v3 = 0;
  v9 = 0;
  v12 = sub_6951CB(this, a2);
  v11 = sub_6951CB(this, a3);
  if ( sub_695259(a2, a3) )
    return 0;
  v6 = 0;
  v13 = 0;
  sub_67F2AD(v8);
  sub_67F2AD(v7);
  if ( v12 )
  {
    do
    {
      if ( v3 >= v11 )
        break;
      if ( sub_6955DE(this, (int)a2, v3, v8) < 0
        || sub_6955DE(this, (int)a3, v3, v7) < 0
        || sub_6956A9((int)v8, (int)v7, &v10) < 0 )
      {
        v6 = 1;
        v13 = 1;
      }
      else
      {
        if ( sub_694EC2(v8[5], v10) )
          v6 = 1;
        if ( sub_694EC2(v10, v7[5]) )
          v13 = 1;
      }
      if ( v6 && v13 )
        break;
      ++v3;
    }
    while ( v3 < v12 );
  }
  if ( v11 >= v12 )
    result = v9;
  else
    result = 4;
  if ( v6 )
    result += 512;
  if ( v13 )
    result += 0x10000;
  if ( v12 < v11 )
    result += (int)&byte_800000;
  return result;
}
