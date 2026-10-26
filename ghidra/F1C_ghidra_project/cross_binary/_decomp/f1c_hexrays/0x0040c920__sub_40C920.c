// f1c  0x0040c920  size=184
int __thiscall sub_40C920(int this)
{
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_15, 3633) )
    sub_4D7AA0(&unk_8AD25C, aEnteredCammanI);
  *(_DWORD *)this = sub_544F50(aMainview);
  dword_5EA550 = 0;
  dword_5EA554 = 0;
  dword_5EA558 = 0;
  dword_5EA500 = 0;
  dword_5EA504 = 0;
  dword_5EA508 = 0;
  sub_40C240((_DWORD *)this);
  sub_40C3B0((_DWORD *)this);
  sub_40C520((_DWORD *)this);
  *(_BYTE *)(this + 45) = 0;
  if ( !sub_40C140((_DWORD *)this) )
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 24);
  return sub_54A200(32, 1);
}
