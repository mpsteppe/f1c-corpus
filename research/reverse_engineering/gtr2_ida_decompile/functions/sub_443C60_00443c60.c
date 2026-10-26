int __thiscall sub_443C60(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 9392);
  if ( *(_DWORD *)(result + 19384) == 5 )
    *(_DWORD *)(result + 19384) = 0;
  *(double *)(this + 1920) = *(double *)(this + 1952);
  *(double *)(this + 1848) = *(double *)(this + 1960);
  *(double *)(this + 1880) = flt_FB1F2C + 273.16;
  *(double *)(this + 3200) = *(double *)(this + 3232);
  *(double *)(this + 3128) = *(double *)(this + 3240);
  *(double *)(this + 3160) = flt_FB1F2C + 273.16;
  *(double *)(this + 4480) = *(double *)(this + 4512);
  *(double *)(this + 4408) = *(double *)(this + 4520);
  *(double *)(this + 4440) = flt_FB1F2C + 273.16;
  *(double *)(this + 5760) = *(double *)(this + 5792);
  *(double *)(this + 5688) = *(double *)(this + 5800);
  *(double *)(this + 5720) = flt_FB1F2C + 273.16;
  return result;
}
