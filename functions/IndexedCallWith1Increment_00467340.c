int __thiscall IndexedCallWith1Increment(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx

  result = this[200];
  if ( result )
  {
    v4 = *(_DWORD *)(result + 20);
    if ( a2 == 1 )
      v5 = v4 + 1;
    else
      v5 = v4 - 1;
    v6 = this[203];
    if ( v6 == 4 )
      ListSelectionClamp(&byte_7C56C0, this[201], v5);
    else
      AIGearSelectionSet(&byte_7C56C0, v6, this[202], v5);
    return MenuOptionValueDisplay(this);
  }
  return result;
}
