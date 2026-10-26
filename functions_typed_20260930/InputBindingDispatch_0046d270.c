int __thiscall InputBindingDispatch(_DWORD **this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // esi

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  v2 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 39);
  v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 41);
  if ( v2 )
    sub_47C360(v2, 1);
  if ( v3 )
    sub_47C360(v3, 0);
  ((void (__thiscall *)(int *))loc_41C540)(dword_5EB978);
  return 0;
}

