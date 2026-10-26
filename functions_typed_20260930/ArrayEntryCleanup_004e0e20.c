int __thiscall sub_4E0E20(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  int result; // eax

  v3 = &this[74 * a2];
  LazyInitCallback(this, (int)(v3 + 81));
  v3 += 98;
  result = LazyInitCallback(this, (int)v3);
  if ( *v3 )
    return FlagFieldBitManipulation(1, 1, 0, 0);
  return result;
}

