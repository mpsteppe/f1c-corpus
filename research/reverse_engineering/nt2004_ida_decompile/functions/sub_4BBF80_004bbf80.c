size_t __thiscall sub_4BBF80(_DWORD *this)
{
  size_t result; // eax
  signed int i; // ecx

  ++this[2];
  result = NumOfElements;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    --*(_DWORD *)(dword_75AAD0[i] + 21116);
    result = NumOfElements;
  }
  return result;
}
