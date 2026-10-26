// f1c  0x004870e0  size=120
int __thiscall sub_4870E0(_DWORD *this, int a2)
{
  int v3; // ebx
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF
  _BYTE v6[2]; // [esp+Eh] [ebp-2h] BYREF

  v3 = this[1];
  if ( a2 >= sub_49ADB0(this + 28) )
  {
    if ( this[50] && (unsigned __int8)sub_49AEC0(a2, v6, &v5) )
      return v3 + v5;
  }
  else if ( (unsigned __int8)sub_49AEC0(a2, v6, &v5) )
  {
    return v3 + v5;
  }
  return -1;
}
