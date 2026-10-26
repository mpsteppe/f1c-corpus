int __thiscall sub_5A35C0(int this)
{
  *(_DWORD *)this = &off_7262B0;
  if ( dword_FB22D0 )
  {
    DestroyWindow(dword_FB22D0);
    UnregisterClassA(lpClassName, *(HINSTANCE *)(this + 1936));
    dword_FB22D0 = 0;
  }
  sub_5A00C0((char *)this);
  if ( *(_BYTE *)(this + 2704) )
  {
    WSACleanup();
    *(_BYTE *)(this + 2704) = 0;
  }
  if ( *(_BYTE *)(this + 3088) && CloseHandle(*(HANDLE *)(this + 3080)) )
    *(_DWORD *)(this + 3080) = 0;
  sub_51F420((int *)(this + 3064));
  sub_51F420((int *)(this + 3064));
  sub_5A08F0((_DWORD *)(this + 3048));
  if ( *(_BYTE *)(this + 3044) && CloseHandle(*(HANDLE *)(this + 3036)) )
    *(_DWORD *)(this + 3036) = 0;
  sub_5A2F40((int *)(this + 3004));
  if ( *(_BYTE *)(this + 3000) && CloseHandle(*(HANDLE *)(this + 2992)) )
    *(_DWORD *)(this + 2992) = 0;
  sub_5A2E40((int *)(this + 2960));
  if ( *(_BYTE *)(this + 2956) && CloseHandle(*(HANDLE *)(this + 2948)) )
    *(_DWORD *)(this + 2948) = 0;
  sub_5A2CF0((int *)(this + 2916));
  if ( *(_BYTE *)(this + 2912) && CloseHandle(*(HANDLE *)(this + 2904)) )
    *(_DWORD *)(this + 2904) = 0;
  if ( *(_BYTE *)(this + 2896) && CloseHandle(*(HANDLE *)(this + 2888)) )
    *(_DWORD *)(this + 2888) = 0;
  sub_525140((int *)(this + 2872));
  if ( *(_BYTE *)(this + 2868) && CloseHandle(*(HANDLE *)(this + 2860)) )
    *(_DWORD *)(this + 2860) = 0;
  sub_525140((int *)(this + 2844));
  if ( *(_BYTE *)(this + 2840) && CloseHandle(*(HANDLE *)(this + 2832)) )
    *(_DWORD *)(this + 2832) = 0;
  sub_59EBB0((int *)(this + 2816));
  if ( *(_BYTE *)(this + 2812) && CloseHandle(*(HANDLE *)(this + 2804)) )
    *(_DWORD *)(this + 2804) = 0;
  sub_59EAD0((int *)(this + 2788));
  if ( *(_BYTE *)(this + 2784) && CloseHandle(*(HANDLE *)(this + 2776)) )
    *(_DWORD *)(this + 2776) = 0;
  sub_51F420((int *)(this + 2760));
  sub_498720((void **)(this + 2708));
  *(_DWORD *)(this + 2396) = &off_72521C;
  return sub_5A66A0(this);
}
