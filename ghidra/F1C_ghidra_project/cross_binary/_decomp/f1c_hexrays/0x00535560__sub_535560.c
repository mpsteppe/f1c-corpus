// f1c  0x00535560  size=62
int __thiscall sub_535560(_DWORD *this)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // eax

  v2 = sub_534E70(this);
  v3 = (sub_534E70(this) << 8) + v2;
  v4 = (sub_534E70(this) << 16) + v3;
  v5 = sub_534E70(this);
  if ( v5 == -1 )
    this[14] = -3;
  return v4 + (v5 << 24);
}
