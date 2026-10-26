void __thiscall sub_60AA40(int this, int a2, int a3, int a4, int a5, int a6, float a7, int a8, char a9)
{
  *(_DWORD *)(this + 204) = a2;
  *(_BYTE *)(this + 237) = a9;
  if ( dword_FB40C8 )
  {
    *(_DWORD *)(this + 208) = 0;
    sub_60A820((_DWORD *)this, 0);
    *(_DWORD *)(this + 212) = 0;
    sub_60A500(0);
    *(_DWORD *)(this + 216) = 0;
    sub_60A3A0((_DWORD *)this, 0);
    *(_DWORD *)(this + 220) = 0;
    sub_60A3F0((_DWORD *)this, 0);
    *(_DWORD *)(this + 224) = 0;
    sub_60A440((_DWORD *)this, 0);
    *(float *)(this + 228) = a7;
  }
}
