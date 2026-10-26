_DWORD *__thiscall sub_40F380(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v4; // esi
  int v5; // edi
  int v6; // esi
  float *v7; // [esp-4h] [ebp-18h]
  float v8[3]; // [esp+8h] [ebp-Ch] BYREF

  result = (_DWORD *)this[7];
  switch ( (unsigned int)result )
  {
    case 0u:
    case 1u:
    case 3u:
    case 4u:
    case 5u:
      result = (_DWORD *)F_3DCollisionDetectionWithAABBTestAndContactResp(
                           this,
                           *(_DWORD *)(this[8] + 208),
                           this[8] + 212);
      break;
    case 2u:
      v4 = this[8];
      v5 = *(_DWORD *)(v4 + 208);
      v8[0] = *(double *)(v4 + 312);
      v8[1] = *(double *)(v4 + 320);
      v8[2] = *(double *)(v4 + 328);
      SceneNodeVisibilityToggle(1);
      v7 = v8;
      goto LABEL_6;
    case 6u:
      result = (_DWORD *)this[8];
      if ( (*(_BYTE *)(*result + 18620) & 1) != 0 )
      {
        v5 = result[442];
        SceneNodeVisibilityToggle(1);
        v7 = (float *)(this[8] + 13548);
LABEL_6:
        VehicleBodyToWheelContactDistanceComputation(v7);
        UIFocusChange(v5, 1);
        result = (_DWORD *)SceneNodeVisibilityToggle(0);
      }
      break;
    case 7u:
      v6 = this[8];
      SceneNodeVisibilityToggle(1);
      VehicleBodyToWheelContactDistanceComputation(0);
      UIFocusChange(v6, 1);
      result = (_DWORD *)SceneNodeVisibilityToggle(0);
      break;
    default:
      return result;
  }
  return result;
}
