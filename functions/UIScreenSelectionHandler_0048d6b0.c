int __thiscall UIScreenSelectionHandler(int this)
{
  int v2; // eax
  const char *v3; // eax

  v2 = FieldGetterAt0x1570(*(_DWORD **)(this + 64));
  *(_DWORD *)(this + 236) = v2;
  if ( v2 )
  {
    v3 = *(const char **)(v2 + 192);
    if ( !v3 )
      v3 = byte_5EA438;
    UIStringComparison((_DWORD *)this, v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 44))(this, 1);
  }
  return 0;
}
