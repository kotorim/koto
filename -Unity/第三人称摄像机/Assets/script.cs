using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class script : MonoBehaviour {
    Transform UD;
    Transform cam;
    float x;
    float y;
    public Transform target;
    public float speedx = 1;
    public float speedy = 1;
	// Use this for initialization
	void Start ()
    {
        Cursor.lockState = CursorLockMode.Locked;
        Cursor.visible = false;
        UD = transform.GetChild(0);
        cam = UD.GetChild(0);
        //cam.LookAt(transform);
    }
	
	// Update is called once per frame
	void Update ()
    {
        x = Input.GetAxis("Mouse X");
        y = Input.GetAxis("Mouse Y");
        transform.Rotate(0, x*speedx, 0);
        UD.Rotate(y*speedy, 0, 0);
        //cam.LookAt(transform);
    }
    void LateUpdate()
    {
        transform.position = target.position;
    }
}
