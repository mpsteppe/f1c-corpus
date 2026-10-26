void __thiscall sub_619170(int this, double *a2)
{
  *(_DWORD *)(this + 192) = *(_DWORD *)a2;
  *(_DWORD *)(this + 196) = *((_DWORD *)a2 + 1);
  *(_DWORD *)(this + 200) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(this + 204) = *((_DWORD *)a2 + 3);
  *(_DWORD *)(this + 208) = *((_DWORD *)a2 + 4);
  *(_DWORD *)(this + 212) = *((_DWORD *)a2 + 5);
  *(double *)(this + 216) = 1.0 / *a2;
  *(double *)(this + 224) = 1.0 / a2[1];
  *(double *)(this + 232) = 1.0 / a2[2];
  sub_618E60((double *)this);
}
