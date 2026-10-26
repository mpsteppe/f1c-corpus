void __thiscall sub_4A5600(int this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  char v4; // bl
  int v5; // eax

  if ( a2 )
  {
    v3 = *(_DWORD **)(this + 8);
    if ( a2 != v3 )
    {
      v4 = 0;
      if ( !v3 )
        goto LABEL_8;
      v5 = *(_DWORD *)(this + 388);
      if ( (v5 != 3 || !*(_BYTE *)(this + 400)) && v5 != 4 )
      {
        v4 = *(_BYTE *)v3 & 1;
        FlagBasedLoopConditionalCall(v3);
LABEL_8:
        *(_DWORD *)(this + 8) = a2;
        if ( v4 )
          sub_4A3390(a2, 0);
        else
          FlagBasedLoopConditionalCall(a2);
      }
    }
  }
}
