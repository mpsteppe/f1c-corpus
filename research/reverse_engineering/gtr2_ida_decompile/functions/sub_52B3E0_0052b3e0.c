int __thiscall sub_52B3E0(_DWORD *this)
{
  int result; // eax
  int i; // ecx

  ++this[3];
  result = dword_757C10;
  for ( i = 0; i < dword_757C10; ++i )
  {
    --*(_DWORD *)(*(&dword_91E088 + i) + 19552);
    result = dword_757C10;
  }
  return result;
}
