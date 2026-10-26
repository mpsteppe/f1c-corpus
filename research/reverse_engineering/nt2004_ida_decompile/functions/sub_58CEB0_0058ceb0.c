BOOL __cdecl sub_58CEB0(int a1, unsigned int a2)
{
  BOOL result; // eax

  result = 0;
  if ( dword_7E483C && a1 >= 0 && *(_WORD *)(*(_DWORD *)(dword_7E483C + 4 * a1) + 10) != 0xFFFF )
    return *(unsigned __int16 *)(*(_DWORD *)(dword_7E483C + 4 * a1) + 10) > a2;
  return result;
}
