#ifndef __SIMPLIFY_H__
#define __SIMPLIFY_H__

#ifdef __cplusplus
extern "C" {
#endif

struct simplify_point {
    double x;
    double y;
    double z;
};

struct simplify_path {
    struct simplify_point *points;
    size_t length;
};

extern struct simplify_path* simplify(const struct simplify_path *path, double tolerance);

#ifdef __cplusplus
}
#endif

#endif /* __SIMPLIFY_H__ */
