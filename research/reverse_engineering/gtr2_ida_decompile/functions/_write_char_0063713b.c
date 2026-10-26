int __usercall write_char@<eax>(int result@<eax>, int a2@<ecx>, _DWORD *a3@<esi>)
{
  bool v3; // sf

  if ( ((*(_BYTE *)(a2 + 12) & 0x40) == 0 || *(_DWORD *)(a2 + 8))
    && ((v3 = *(_DWORD *)(a2 + 4) - 1 < 0, --*(_DWORD *)(a2 + 4), v3)
      ? (result = sub_637022((char)result, (int *)a2))
      : (**(_BYTE **)a2 = result, ++*(_DWORD *)a2, result = (unsigned __int8)result),
        result == -1) )
  {
    *a3 = -1;
  }
  else
  {
    ++*a3;
  }
  return result;
}
