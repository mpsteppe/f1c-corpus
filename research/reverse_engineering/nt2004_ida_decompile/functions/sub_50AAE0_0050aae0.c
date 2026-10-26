int __thiscall sub_50AAE0(char *this)
{
  int v2; // edi
  _DWORD *v3; // edi
  int v4; // ebp
  void *v5; // edx
  int v6; // edi
  int v7; // edx
  _DWORD *v8; // edi
  int v9; // ebp
  _BYTE *v10; // ecx
  int result; // eax
  int v12; // ecx
  int v13; // edx

  if ( dword_7DA9B8 && *((_DWORD *)this + 1) )
  {
    sub_50AFB0(this);
    sub_5973D0(*((_DWORD *)this + 1));
    sub_418600(dword_6291D0, *(_DWORD *)(*(_DWORD *)this + 25248), 0);
  }
  sub_50EC40(this);
  sub_50E3C0(this);
  sub_509870(this + 4);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  v2 = *((_DWORD *)this + 38);
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  if ( v2 )
  {
    sub_4667A0((_DWORD *)(v2 + 72));
    sub_4DB110((int *)(v2 + 56));
    sub_4DB110((int *)(v2 + 40));
    if ( *(_DWORD *)(v2 + 32) )
      sub_5BE8AE();
    if ( *(_DWORD *)(v2 + 24) )
      sub_5BE8AE();
    sub_40D5B0((LPVOID *)(v2 + 16));
    sub_40D5B0((LPVOID *)(v2 + 8));
    sub_40D5B0((LPVOID *)v2);
    sub_5BE8AE();
  }
  *((_DWORD *)this + 38) = 0;
  this[156] = 0;
  v3 = this + 220;
  v4 = 4;
  do
  {
    sub_509980(v3);
    v3 += 76;
    --v4;
  }
  while ( v4 );
  sub_509870(this + 1556);
  sub_509870(this + 1624);
  v5 = this + 1692;
  v6 = 12;
  do
  {
    sub_509870(v5);
    v5 = (void *)(v7 + 68);
    --v6;
  }
  while ( v6 );
  *((_DWORD *)this + 627) = 0;
  *((_DWORD *)this + 628) = 0;
  *((_DWORD *)this + 629) = 0;
  *((_DWORD *)this + 630) = 0;
  *((_DWORD *)this + 631) = 0;
  *((_DWORD *)this + 632) = 0;
  *((_DWORD *)this + 633) = 0;
  *((_DWORD *)this + 634) = 0;
  *((_DWORD *)this + 636) = 0;
  *((_DWORD *)this + 637) = 0;
  *((_DWORD *)this + 638) = 0;
  *((_DWORD *)this + 635) = 0;
  *((_DWORD *)this + 639) = 0;
  *((_DWORD *)this + 640) = 0;
  *((_DWORD *)this + 641) = 0;
  *((_DWORD *)this + 642) = 0;
  *((_DWORD *)this + 679) = 0;
  *((_DWORD *)this + 683) = 0;
  *((_DWORD *)this + 684) = 0;
  *((_DWORD *)this + 685) = 0;
  *((_DWORD *)this + 686) = 0;
  *((_DWORD *)this + 687) = 0;
  *((_DWORD *)this + 688) = 0;
  *((_DWORD *)this + 689) = 0;
  *((_DWORD *)this + 690) = 0;
  *((_DWORD *)this + 691) = 0;
  *((_DWORD *)this + 698) = 0;
  *((_DWORD *)this + 699) = 0;
  *((_DWORD *)this + 700) = 0;
  *((_DWORD *)this + 701) = 0;
  *((_DWORD *)this + 702) = 0;
  *((_WORD *)this + 1406) = 0;
  *((_DWORD *)this + 704) = 0;
  *((_DWORD *)this + 705) = 0;
  *((_DWORD *)this + 706) = 0;
  *((_DWORD *)this + 707) = 0;
  *((_DWORD *)this + 717) = 0;
  *((_DWORD *)this + 718) = 0;
  this[2876] = 0;
  this[2877] = 0;
  *((_DWORD *)this + 720) = 0;
  this[2884] = 0;
  this[2885] = 0;
  this[2887] = 0;
  this[2888] = 0;
  *((_DWORD *)this + 723) = 0;
  *((_DWORD *)this + 726) = -8388609;
  *((_DWORD *)this + 725) = -1;
  *((_DWORD *)this + 727) = 1065353216;
  *((_DWORD *)this + 848) = 0;
  memset(this + 3396, 0, 0x48u);
  *((_DWORD *)this + 867) = 0;
  v8 = this + 3472;
  v9 = 15;
  do
  {
    sub_508930(v8);
    v8 += 187;
    --v9;
  }
  while ( v9 );
  this[2912] = 0;
  v10 = this + 2916;
  do
  {
    result = sub_5099B0(v10);
    v10 = (_BYTE *)(v12 + 28);
  }
  while ( v13 != 1 );
  return result;
}
