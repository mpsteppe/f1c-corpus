void __thiscall sub_61B620(int this, const char *a2, double a3, _DWORD *a4)
{
  char *v5; // eax

  v5 = (char *)operator new(strlen(a2) + 1);
  *(_DWORD *)this = v5;
  strcpy(v5, a2);
  *(double *)(this + 176) = a3;
  *(double *)(this + 184) = 1.0 / a3;
  *(_DWORD *)(this + 192) = *a4;
  *(_DWORD *)(this + 196) = a4[1];
  *(_DWORD *)(this + 200) = a4[2];
  *(_DWORD *)(this + 204) = a4[3];
  *(_DWORD *)(this + 208) = a4[4];
  *(_DWORD *)(this + 212) = a4[5];
  *(double *)(this + 216) = 1.0 / *(double *)(this + 192);
  *(double *)(this + 224) = 1.0 / *(double *)(this + 200);
  *(double *)(this + 232) = 1.0 / *(double *)(this + 208);
  sub_618E60((double *)this);
}
