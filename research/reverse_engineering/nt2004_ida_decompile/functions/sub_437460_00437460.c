int __thiscall sub_437460(int *this)
{
  void *v2; // eax
  int v3; // eax
  int v5; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  if ( this[3] )
    sub_4379D0();
  v2 = operator new(4u);
  if ( v2 )
    v3 = sub_459A60(v2);
  else
    v3 = 0;
  this[3] = v3;
  if ( !v3 || sub_437550(this) )
    return 1;
  v5 = 1119092736;
  v7 = 1056964608;
  v6 = 1167867904;
  sub_459C80(aGridwalkCam);
  sub_459C90(2);
  sub_459CB0(&v5, 0);
  sub_459CE0(0);
  sub_459D80(this[7]);
  sub_459CD0(1067450368);
  sub_459CC0(&v7, &v6);
  sub_459B30(this[3]);
  sub_40C490((_DWORD **)&dword_6291CC, this[3]);
  return 0;
}
