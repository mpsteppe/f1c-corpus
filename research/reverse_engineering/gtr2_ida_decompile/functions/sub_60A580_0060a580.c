void __thiscall sub_60A580(int this, float a2)
{
  if ( a2 != *(float *)(this + 228) )
  {
    *(float *)(this + 228) = a2;
    (*(void (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)dword_FB40C8 + 276))(
      dword_FB40C8,
      *(_DWORD *)(this + 204),
      8,
      *(_DWORD *)(this + 228));
  }
}
