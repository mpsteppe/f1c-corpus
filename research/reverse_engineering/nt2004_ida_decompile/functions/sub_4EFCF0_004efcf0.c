void __thiscall sub_4EFCF0(int this, float a2, char *FileName)
{
  int v4; // ecx

  v4 = dword_7D6BB4;
  if ( dword_7D6BB4 )
  {
    if ( FileName )
    {
      sub_4EF930(this, this, FileName);
      v4 = dword_7D6BB4;
    }
    if ( *(_BYTE *)(this + 20) )
    {
      if ( v4 )
      {
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 32))(v4, 1008981770);
        if ( flt_767898 != 0.0 )
        {
          *(_DWORD *)(this + 24) = 1;
          if ( a2 <= 0.0 )
            *(float *)(this + 28) = flt_767898;
          else
            *(float *)(this + 28) = flt_767898 / a2;
        }
      }
    }
  }
}
