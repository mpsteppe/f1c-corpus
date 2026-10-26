void __thiscall sub_43AA80(int this)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7

  if ( !*(_BYTE *)(this + 948) )
  {
    v1 = *(double *)(this + 1008);
    *(_BYTE *)(this + 948) = 1;
    *(double *)(this + 1008) = v1 * 0.18;
    *(double *)(this + 564) = *(double *)(this + 564) * 4.0;
    *(double *)(this + 1232) = *(double *)(this + 1232) * 0.7;
    *(double *)(this + 688) = *(double *)(this + 688) * 0.7;
    *(double *)(this + 1240) = *(double *)(this + 1240) * 0.7;
    *(double *)(this + 704) = *(double *)(this + 704) * 0.7;
    v2 = *(double *)(this + 1000) * 0.25;
    if ( v2 > 10.0 )
      v2 = 10.0;
    v3 = v2 / *(double *)(this + 876);
    *(_DWORD *)(this + 604) = 0;
    *(_DWORD *)(this + 608) = 1072693248;
    *(_DWORD *)(this + 572) = -1717986918;
    *(_DWORD *)(this + 576) = 1069128089;
    *(double *)(this + 984) = v3;
  }
}
