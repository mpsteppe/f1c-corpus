int __thiscall sub_46FC30(_DWORD *this)
{
  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  BufferInitWith10fDefaults(flt_5EA618);
  if ( dword_7D0410 == 4 )
  {
    sub_4A0760();
    GuardedFunctionDispatch(this, (int)aChPostracedriv);
    return 0;
  }
  else if ( dword_7D0410 == 5 )
  {
    if ( StateCheckWrapper(dword_7CD25C) )
      LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMphostgrid, -1);
    else
      LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMpclientgrid, -1);
    return 0;
  }
  else
  {
    GuardedFunctionDispatch(this, (int)aMainMenu);
    dword_5CC9E8 = 3;
    return 0;
  }
}

