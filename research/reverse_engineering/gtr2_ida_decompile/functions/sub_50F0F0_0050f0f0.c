int __thiscall sub_50F0F0(int this)
{
  int v3; // eax
  int v4; // edx
  unsigned __int8 v5; // [esp+1Fh] [ebp-5h] BYREF
  int v6; // [esp+20h] [ebp-4h] BYREF

  switch ( *(_DWORD *)(this + 10848) )
  {
    case 0:
    case 5:
      return off_16C9350();
    case 1:
      v6 = 0;
      sub_4762A0((int *)(this + 2160), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 2868), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 3192), &v6);
      v6 = 1065353216;
      sub_409B80((float *)(this + 3732), (float *)&v6);
      return off_16C9368();
    case 2:
      v6 = 0;
      sub_4762A0((int *)(this + 2160), &v6);
      v6 = 1065353216;
      sub_409B80((float *)(this + 3732), (float *)&v6);
      v6 = 0;
      sub_4762A0((int *)(this + 4056), &v6);
      v6 = 1;
      sub_4762A0((int *)(this + 4380), &v6);
      v5 = 0;
      sub_478D00((unsigned __int8 *)(this + 4680), &v5);
      v6 = 3;
      sub_4762A0((int *)(this + 12576), &v6);
      v6 = 0x7FFF;
      sub_4762A0((int *)(this + 12900), &v6);
      v6 = 1036831949;
      sub_409B80((float *)(this + 13224), (float *)&v6);
      v6 = 1;
      sub_4762A0((int *)(this + 13608), &v6);
      v6 = 5;
      sub_4762A0((int *)(this + 13932), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14604), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14928), &v6);
      v6 = 6;
      sub_4762A0((int *)(this + 10756), &v6);
      return off_16C9350();
    case 3:
      v6 = 0;
      sub_4762A0((int *)(this + 2160), &v6);
      v6 = 1065353216;
      sub_409B80((float *)(this + 3732), (float *)&v6);
      v6 = 0;
      sub_4762A0((int *)(this + 4056), &v6);
      v6 = 1;
      sub_4762A0((int *)(this + 4380), &v6);
      v5 = 0;
      sub_478D00((unsigned __int8 *)(this + 4680), &v5);
      v6 = 3;
      sub_4762A0((int *)(this + 12576), &v6);
      v6 = 0x7FFF;
      sub_4762A0((int *)(this + 12900), &v6);
      v6 = 1045220557;
      sub_409B80((float *)(this + 13224), (float *)&v6);
      v6 = 1;
      sub_4762A0((int *)(this + 13608), &v6);
      v6 = 7;
      sub_4762A0((int *)(this + 13932), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14604), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14928), &v6);
      v6 = 8;
      sub_4762A0((int *)(this + 10756), &v6);
      return off_16C9350();
    case 4:
      v6 = 0;
      sub_4762A0((int *)(this + 2160), &v6);
      v6 = 1065353216;
      sub_409B80((float *)(this + 3732), (float *)&v6);
      v6 = 0;
      sub_4762A0((int *)(this + 4056), &v6);
      v6 = 1;
      sub_4762A0((int *)(this + 4380), &v6);
      v5 = 0;
      sub_478D00((unsigned __int8 *)(this + 4680), &v5);
      v6 = 3;
      sub_4762A0((int *)(this + 12576), &v6);
      v6 = 0x7FFF;
      sub_4762A0((int *)(this + 12900), &v6);
      v6 = 1050253722;
      sub_409B80((float *)(this + 13224), (float *)&v6);
      v6 = 1;
      sub_4762A0((int *)(this + 13608), &v6);
      v6 = 9;
      sub_4762A0((int *)(this + 13932), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14604), &v6);
      v6 = 0;
      sub_4762A0((int *)(this + 14928), &v6);
      v6 = 10;
      sub_4762A0((int *)(this + 10756), &v6);
      return off_16C9350();
    default:
      v3 = *(_DWORD *)(this + 10856);
      v4 = *(_DWORD *)(this + 10860);
      *(_DWORD *)(this + 10848) = 0;
      if ( v3 <= 0 )
      {
        if ( v4 < 0 )
          *(_DWORD *)(this + 10848) = v4;
      }
      else
      {
        *(_DWORD *)(this + 10848) = v3;
      }
      return off_16C9350();
  }
}
