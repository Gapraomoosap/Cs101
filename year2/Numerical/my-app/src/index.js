import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';
import Bisection from './page/Root_of_Equation/Bisection/Bisection_search';
import GraphPage from './page/Root_of_Equation/Graphical/GraphPage';
import FalsePage from './page/Root_of_Equation/False/FalsePosition';
import OnePointPage from './page/Root_of_Equation/One_point/onepointPage';
import NewtonPage from './page/Root_of_Equation/Newton_Raphson/newtonPage';
import SecantPage from './page/Root_of_Equation/Secant/secantPage';

import {
  createBrowserRouter,
  RouterProvider,
} from "react-router-dom";

const router = createBrowserRouter([
  {
    path: "/",
    element: <App />,
  },
  {
    path: "/Bisection_search",
    element: <Bisection />,
  },
  {
    path: "/False-position_methods",
    element: <FalsePage />,
  },
  {
    path: "/Graphical_methods",
    element: <GraphPage />,
  },
  {
    path: "/Newton-Raphson_methods",
    element: <NewtonPage />,
  },
  {
    path: "/One-point_Iteration_methods",
    element: <OnePointPage />,
  },
  {
    path: "/Secant_methods",
    element: <SecantPage />,
  },
  {
    path: "/Conjugate_Gradient_Methods",
    element: <Bisection />,
  },
  {
    path: "/Cramer's_rule",
    element: <Bisection />,
  },
  {
    path: "/Guass_elimination",
    element: <Bisection />,
  },
  {
    path: "/Guass_Jordan_elimination",
    element: <Bisection />,
  },
  {
    path: "/Jacobi_Iteration_Methods",
    element: <Bisection />,
  },
  {
    path: "/Matrix_Inversion",
    element: <Bisection />,
  },
  {
    path: "/Lagrange_interpolation",
    element: <Bisection />,
  },
  {
    path: "/Newton_divied-differences",
    element: <Bisection />,
  },
  {
    path: "/Spline_interpolation",
    element: <Bisection />,
  },
  {
    path: "/Simpson_Rule",
    element: <Bisection />,
  },
  {
    path: "/Trapezoidal_Rule",
    element: <Bisection />,
  },
  {
    path: "/Composite_Simpson_Rule",
    element: <Bisection />,
  },
  {
    path: "/Composite_Trapezoidal_Rule",
    element: <Bisection />,
  },
  {
    path: "/Multiple_Regression",
    element: <Bisection />,
  },
  {
    path: "/Simple_Regression",
    element: <Bisection />,
  },
]);

ReactDOM.createRoot(document.getElementById("root")).render(
  <React.StrictMode>
    <RouterProvider router={router} />
  </React.StrictMode>
);


reportWebVitals();
